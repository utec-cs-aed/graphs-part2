# Algoritmos y Estructura de Datos
## Grafos
--------

## Integrantes
- 
- 
- 

----

## Instrucciones

* Implementar un grafo dinámico (inserciones. eliminaciones, búsquedas, ...)
* Considerar los dos tipos de grafos: dirigidos y no-dirigidos.
* No considerar loops ni multi-arista. 
* Implementar todos los algoritmos de búsqueda vistos en clase (Graph/Algorithms) para ambos tipos de grafos
* Proponer ejemplos de prueba

### Ejemplo de uso del algoritmo de busqueda:
```cpp
//Given the graph
DirectedGraph<char, int> graph;

//Apply the A* algorithm
AStar<char, int> astar(&graph, "A", "Z", vector<int> heuristics);
unordered_map<char, char> result = astar.apply();
```

> **PD:** Esta tarea tendra peso doble
