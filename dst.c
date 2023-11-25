import copy
import random
def initialize_network():
 network = {
 "A": {"B": float('inf'), "C": float('inf')},
 "B": {"A": float('inf'), "C": float('inf'), "D": float('inf')},
 "C": {"A": float('inf'), "B": float('inf'), "D": float('inf')},
 "D": {"B": float('inf'), "C": float('inf')}
 }
 for node in network:
 for neighbor in network[node]:
 if node == neighbor:
 network[node][neighbor] = 0
 else:
 network[node][neighbor] = random.randint(1, 10)
 return network
def distance_vector_routing(network):
 for _ in range(10):
 prev_tables = copy.deepcopy(network)
 for node in network:
 for neighbor in network[node]:
 distance_to_neighbor = network[node][neighbor]
 min_distance = min(distance_to_neighbor, min(network[neighbor].values()) + 1)
 network[node][neighbor] = min_distance
 if prev_tables == network:
 break
def print_routing_tables(network):
 for node in network:
 print(f"\nRouting table for Node {node}:")
 print("Destination\tDistance")
 for destination, distance in network[node].items():
 print(f"{destination}\t\t{distance}")
def main():
 network = initialize_network()
 distance_vector_routing(network)
 print("\nFinal Routing Tables after Convergence:")
 print_routing_tables(network)
if __name__ == "__main__":
 main()
