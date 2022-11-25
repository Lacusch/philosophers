# TODO

```Text
Started on 24. of November fininsh ASAP.
```

## Working on right now

- Setting up flags with enum.
- ~~Handle parcing~~

```Bash
./philo \
number_of_philosophers \
time_to_die \
time_to_eat time_to_sleep \
(number_of_times_each_philosopher_must_eat) #optional
```

## Set up philosophers

- Create struct for the philo's atributes itself
  - Left fork
  - Right fork
  - ~~time to die~~
  - ~~time to eat~~
  - ~~time to think~~
- Create the forks
  - Is taken flag with ```enum``` or ```bool```
  - ```Mutex``` to lock it when taken
- Code the actions (eat, sleep, thing)
- Set up flags with erno for the different scenarios
