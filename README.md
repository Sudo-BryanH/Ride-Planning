# Ride-Planning Algorithm

## Introduction: 

This is a program to decide car rides. Given a set of unique passengers and drivers, this program will decide on the best way to assign 
passengers to a driver. This will be a great program to decide how car rides between small groups of friends can be arranged. 

## Function
Passengers will be identified by their name, contacts, gender, and group. Drivers will be identified by their name, contacts, groups, gender, and maximum occupancy (minus themselves). This program will prioritize those who cannot take public transport, groups, then gender and fill up the drivers as soon as possible. This is done by using a hashmap to ensure an amortized O(1) search and insertion for each group. There will be 3 sections to this hashmap, the group, gender, and miscellanious section. Passengers and drivers will be placed in their respective groups (or gender/misc if no group provided) before the algorithm begins as nodes to a linked list. Each passenger will try to be assigned to a driver in the group stage. If not possible, each passenger will be assigned based on their gender. ~~The last resort is to put those remaining into remaining cars. The results will show all assignments and all those who could not be assigned.~~ [sorting miscellaneous people has not been implemented yet]

### Limitations of this implementation
1) Say a group is co-ed. This since this software first distinguishes between group, then gender, gender will be irrelevant as groups will be prioritized and a car assignment may be co-ed. This can be reconciled by creating a subgroup that splits genders.
- e.g. Say you have a group "AA" that is co-ed. You may separate this into "AA-f" and "AA-m" to allow the program to distinguish between male and female riders and drivers.

2) The worst case of this algorithm is θ(n*m) given n passengers and d drivers delcared. This occurs when theere are no matching groups between driver and passenger and driver gender is not labelled. This will cause all passengers to be shuffled from the group selection stage, the gender selection stage and then the miscellanious selection stage, each pass taking O(n) time. 



## Citations

catch.hpp used for testing is copied from https://github.com/catchorg/Catch2.git