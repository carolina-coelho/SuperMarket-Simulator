# SuperMarket Simulatior System

This project implements a dynamic simulation system for supermarket checkout management using the C programming language.
The system simulates the lifecycle of a supermarket operation: from loading product and staff databases to managing real-time
customer queues at various checkout counters (cashes). It leverages Generic Linked Lists to achieve polymorphism, allowing a single
data structure to manage different entities like Customers, Products, and Employees.

## Architecture Overview

The system follows a modular design where data management is separated from simulation logic.

The workflow is:
**Data Ingestion** (`.txt` files) → **Resource Allocation** (Staff to Cashes) → **Simulation Loop** (Customer Flow) → **Metrics & Output**.

* **Generic Data Layer**: A robust implementation of a Linked List/Queue that handles `void*` pointers.
* **Time Management**: A dedicated engine to control simulation speed and synchronization.
* **Entity Modules**: Encapsulated logic for `Clients`, `Products`, and `Staff`.


## Project Structure

```
├── main.c                # Application entry point and simulation 
├── ListaGenerica.c/h     # Core ADT: Polymorphic Linked List and Queue
├── Caixa.c/h             # Checkout counter logic and queue management
├── Cliente.c/h           # Customer data, including personalized shopping lists
├── Produtos.c/h          # Product database management and processing times
├── Funcionarios.c/h      # Staff records and assignment logic
├── Tempo.c/h             # Simulation clock with adjustable velocity
├── Uteis.c/h             # Randomization and helper functions
├── Hashing.c/h           # Hash table implementation for optimized lookups
├── Dados.h               # Global definitions and constants
└── Data Files
    ├── produtos.txt      # Database of available products
    ├── clientes.txt      # List of registered customers
    └── funcionarios.txt  # Staff roster
```

## Technologies Used

| Technology | Purpose |
| :--- | :--- |
| **C (ISO C11)** | Core implementation language |
| **GCC** | Recommended compiler |
| **Modular Design** | High cohesion and low coupling through header files |
| **Generic ADTs** | Reusable data structures using function pointers |
| **File I/O** | Persistence and data loading from structured text files |

## Key Features

### 1. Polymorphic Linked List (`ListaGenerica`)
The backbone of the project. It uses `void *Info` to store any data type and function pointers for specialized operations:
* `fdest`: Custom destructor for complex structures.
* `fcomp`: Custom comparison logic for searching/sorting.
* `ShowLG`: Generic display interface.

### 2. Time-Scaled Simulation (`Tempo`)
The simulation doesn't just run in real-time; it features a `VELOCIDADE` (Velocity) factor.
* **Simulation Clock**: Tracks "Supermarket Time" independently of CPU time.
* **Wait Logic**: Synchronized delays to mimic product scanning and payment durations.

### 3. Queue Management (`Caixa`)
Each checkout counter manages its own `FilaGenerica` (Generic Queue). The system can:
* Calculate total wait times.
* Assign specific employees to counters.
* Track the number of products processed per session.

### 4. Automated Data Loading
The system automatically parses external databases:
* **Products**: Loads IDs, names, prices, and scan times (`TCAIXA`).
* **Staff**: Loads employee names and credentials to staff the counters.


## Simulation Workflow
1. **Bootstrapping**: The program reads `funcionarios.txt` and `produtos.txt` to populate the system memory.
2. **Clock Setup**: The `StartRelogio` function initializes the simulation start time (e.g., 09:00:00).
3. **Customer Entry**: Customers are assigned product lists (from `produtos.txt`) and enter the checkout area.
4. **Processing**: Customers join queues based on availability.
  * The system calculates the exit time based on: `(Number of Products * Product Scan Time) + Base Payment Time`.
5. **Shutdown**: The simulation ends, and the generic structures are safely deallocated (`DestruirLG`).

This project serves as a practical application of advanced C concepts, focusing on:
* **Memory Efficiency**: Dynamic allocation with rigorous cleanup.
* **Generic Programming**: Abstracting data from structures.
* **Real-world Modeling**: Simulating concurrent processes (queues) and time.
