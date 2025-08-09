



t_node *get_cheapest(t_node *stack);                // Obtener nodo con cheapest = 1
void move_to_top(t_node **stack, t_node *target);   // Rotar hasta traer target arriba
void execute_cheapest_move(t_node **stack_a, t_node **stack_b); // Ejecutar movimiento óptimo