[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/5h77x3DJ)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=21623276&assignment_repo_type=AssignmentRepo)
# Data Structures — Assignment 1: DSU (Union-Find)

This is the **first assignment** for the Data Structures course.  
The goal is to implement the **Disjoint Set Union (Union-Find)** data structure with support for:

- **Path compression** in `findSet`
- **Union by size/rank** in `unionSet`

---

## Task Description
You will receive queries in the following format:

- `+ a b` → union the sets containing `a` and `b`
- `? a b` → check if `a` and `b` are in the same set. Print `YES` or `NO`.

### Example Input
```
6 7
+ 1 2
+ 3 4
? 1 3
+ 2 3
? 1 4
? 5 6
+ 5 6
```

### Example Output
```
NO
YES
NO
```

---

## Instructions
- Edit only the DSU functions in the starter file:
  - C++ → `starter/dsu.cpp`
  - Java → `starter/DSU.java`
- Do **not** change input/output format or main function.
- Submit **one language only** (C++ or Java).
- Read and understand all the starter code carefully, you will be asked about it for verification later.

---

## Testing
Your solution will be automatically tested with multiple input/output files.  
Make sure your output matches exactly for all queries.

---

Good luck