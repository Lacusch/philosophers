# TODO

```Text
Started on 24. of November fininsh ASAP.
30 hours from 11.02
```

## Working on right now

- Setting up flags with enum.
- ~~Handle parcing~~

```Bash
./philo \
number_of_philosophers \
time_to_die \
time_to_eat \
time_to_sleep \
(number_of_times_each_philosopher_must_eat) #optional
```

## Set up philosophers

- Create struct for the philo's atributes itself
  - ~~Left fork~~
  - ~~Right fork~~
  - ~~time to die~~
  - ~~time to eat~~
  - ~~time to think~~
- ~~Create the forks~~
  - ~~Is taken flag with ```enum``` or ```bool```~~
  - ~~```Mutex``` to lock it when taken~~
- Create mutex for each operation
  - ~~write~~
  - ~~meal~~
  - ~~flag~~
  - ~~death_check~~
  - ~~death_flag?~~
  - ~~full_flag?~~
  - create functions to set up the locks
- ~~Create a routine to test with one thread~~
- ~~Code the actions (eat, sleep, thing)~~
- Make even philos take a left fork first and uneven philos a right fork first
  - most likely use a delay
- ~~Set up flags with erno for the different scenarios~~

## Stuff to implement

- Write a function to check if the philo has died or not and run it inside each operation.
- Write a monitoring function to run inside the main loop.
- Fix other philo /philos doing stuff after one died (sleeping)

- philos are eating 1 more times
- put philos in a folder
- replace atoi
- fixed the leaks
- Fix flags not working
