# Algoritmos y Estructura de Datos
## Grafos
--------

## Integrantes
- 
- 
- 

----

* El grafo debe ser dinámico (inserciones. eliminaciones, búsquedas, ...)
* Se debe implementar los dos tipos de grafos: dirigidos y no-dirigidos.
* No considerar loops ni multi-arista. 
* Implementar todos los algoritmos de búsqueda vistos en clase (Graph/Algorithms)


### Ejemplo de uso del algoritmo de busqueda:
```cpp
//Given the graph
DirectedGraph<char, int> graph;

//Apply the A* algorithm
AStar<char, int> astar(&graph, "A", "Z", vector<int> heuristics);
unordered_map<char, char> result = astar.apply();

```

> **PD:** Puntos extras sobre Evaluación Continua si se implementa una GUI.
