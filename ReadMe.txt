Learning 10000

The goal of this project is to create an AI capable of learning how to play the dice game 10000 such that it finds a policy that is significantly better than a random valid action selection policy. A bonus goal is to learn it well enough to play well against a human. 

It will utilize reinfoced learning principles and the Expected Sarsa algorithm.
It will create the state space lazily and generate valid actions as new states are found. (sacrifices runtime speed for memory
efficiency and simplicity of implementation)


Current Status:
General framework is in place, encoding of data for efficient memory utilization and dynamic creation of valid actions and 
state space management. 

TODO:
create functions to manage the flow of the game upon actions being taken, and return data used by ES algorithm
implement the ES algorithm itself 
