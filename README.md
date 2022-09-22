# SIR-SM
Variation of the SIR model based on a probabilistic cellular automata with a basic coding in C.
 
The model was presented and discussed in Schimit, P. H. T.; Monteiro, L.H.A. . On the basic reproduction number and the topological properties of the contact network: An epidemiological study in mainly locally connected cellular automata. Ecological Modelling, p. 1034-1042, 2009.
 
# How to use the code

The input variables are:

**SIDE**: size of the square lattice side.

**ITER**: number of iterations to run the model.

**C** and **r**: neighborhood variables as described in the original paper Schimit and Monteiro, 2009. C is the number of connections per cell and r is the maximum radius for these connections.

**K**: parameter related to disease infectivity.

**PC**: probability of cure.

**PD**: probability of death due to the disease.

**PN**: probability of death due to natural causes.

**iniI**: initial percentage of infected individuals.

**iNeigh**:
- NEIGH_MOORE: Moore neighborhood to consider cells' contacts.
- NEIGH_VONNE: Von Neumann neighborhood.
- NEIGH_SM: Neighborhood used in Schimit and Monteiro, 2009.




