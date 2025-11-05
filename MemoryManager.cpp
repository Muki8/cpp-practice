#include <iostream>
#include <cstddef>
#include <iomanip>

using namespace std;

#define HEAP_SIZE 1024 * 1024 // 1 MB de memoria simulada

class MemoryManager {
private:
    struct Block {
        size_t size;
        bool free;
        Block* next;
    };

    char* heap;
    Block* freeList;
    size_t totalAllocated;
    size_t totalFree;

public:
    MemoryManager() {
        heap = new char[HEAP_SIZE];
        initialize();
    }

    ~MemoryManager() {
        delete[] heap;
    }

    void initialize() {
        freeList = reinterpret_cast<Block*>(heap);
        freeList->size = HEAP_SIZE - sizeof(Block);
        freeList->free = true;
        freeList->next = nullptr;

        totalAllocated = 0;
        totalFree = freeList->size;
    }

    void* allocate(size_t size) {
        Block* current = freeList;

        while (current != nullptr) {
            if (current->free && current->size >= size) {
                // Si sobra espacio, dividimos el bloque
                if (current->size > size + sizeof(Block)) {
                    Block* newBlock = reinterpret_cast<Block*>(
                        reinterpret_cast<char*>(current) + sizeof(Block) + size);
                    newBlock->size = current->size - size - sizeof(Block);
                    newBlock->free = true;
                    newBlock->next = current->next;
                    current->next = newBlock;
                }

                current->free = false;
                totalAllocated += current->size;
                totalFree -= current->size;
                current->size = size;

                return reinterpret_cast<char*>(current) + sizeof(Block);
            }
            current = current->next;
        }

        cerr << "[Error] No hay suficiente memoria disponible." << endl;
        return nullptr;
    }

    void deallocate(void* ptr) {
        if (ptr == nullptr) return;

        Block* block = reinterpret_cast<Block*>(
            reinterpret_cast<char*>(ptr) - sizeof(Block));

        if (block->free) {
            cerr << "[Error] Intento de liberar un bloque ya libre." << endl;
            return;
        }

        block->free = true;
        totalAllocated -= block->size;
        totalFree += block->size;

        // Fusionar bloques contiguos libres
        Block* current = freeList;
        while (current != nullptr) {
            if (current->free && current->next && current->next->free) {
                current->size += sizeof(Block) + current->next->size;
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
    }

    void showStats() const {
        cout << fixed << setprecision(2);
        cout << "\n=== ESTADÍSTICAS DE MEMORIA ===" << endl;
        cout << "Total reservado: " << HEAP_SIZE / 1024.0 << " KB" << endl;
        cout << "Memoria en uso:  " << totalAllocated / 1024.0 << " KB" << endl;
        cout << "Memoria libre:   " << totalFree / 1024.0 << " KB" << endl;
    }

    void debugBlocks() const {
        cout << "\n=== ESTADO DE BLOQUES ===" << endl;
        Block* current = freeList;
        int i = 0;
        while (current != nullptr) {
            cout << "Bloque " << i++
                 << " | Tamaño: " << current->size
                 << " bytes | Estado: "
                 << (current->free ? "Libre" : "Ocupado") << endl;
            current = current->next;
        }
    }
};

// === PROGRAMA PRINCIPAL ===
int main() {
    MemoryManager mm;

    cout << "=== Simulador de administrador de memoria ===" << endl;

    void* p1 = mm.allocate(200);
    void* p2 = mm.allocate(500);
    void* p3 = mm.allocate(100);

    mm.showStats();
    mm.debugBlocks();

    mm.deallocate(p2);
    mm.deallocate(p1);
    mm.deallocate(p3);

    cout << "\nDespués de liberar:" << endl;
    mm.showStats();
    mm.debugBlocks();

    system("pause");
    return 0;
}
