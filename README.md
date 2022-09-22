# SIR-SM
Variation of the SIR model based on a probabilistic cellular automata with a basic coding in C.
 
The model was presented and discussed in Schimit, P. H. T.; Monteiro, L.H.A. . On the basic reproduction number and the topological properties of the contact network: An epidemiological study in mainly locally connected cellular automata. Ecological Modelling, p. 1034-1042, 2009.
 
# How to use the code

## The input variables are:

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

Variables PC, PD, PN, K, C, r and iniI can be passed by command line using --PC, --PD, --PN, --K, --C, --r and --iniI, respectively. The other ones are hard-coded.

## Compiling the code

For Windows, the project is set using Dev-C++ software (https://sourceforge.net/projects/orwelldevcpp/) with its proper .dev file. Easy to install and use a simple project.

For Linux, the build folder helps to compile the code using CMAKE. Open a terminal on the build folder and run

cmake ..

cmake --build .

## Running the code

The results files are written in the results folder. It can be changed in the data.ini file (/code/data.ini for Windows and /code/build/data.ini for Linux).

If the files SIR-SM_SIM_0000.csv existis in the folder, the new result will be written in the file SIR-SM_SIM_0001.csv, that is, it increments the file number.

## License

This content is licensed under [Creative Commons Attribution-ShareAlike 4.0 Internacional](http://creativecommons.org/licenses/by-sa/4.0/).

[![CC BY-SA 4.0](https://licensebuttons.net/l/by-sa/4.0/88x31.png)](http://creativecommons.org/licenses/by-sa/4.0/)
