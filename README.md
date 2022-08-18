# Philosophers

Thread is the keyword of this project!
Philosophres dynamics are resolved using threads and mutex. A separate thread has been implemented for monitoring Philosophers, to check if any philosophers have died and warn others that they need to stop immediately.

Thread é a palavra chave desse projeto!
A dinamica dos Philosophres é resolvida usando threads e mutex. Uma thread separada foi implementada para o monitoramento do Philosophers,para verificar se algum filósofo morreu e avisa os outros que precisam parar imediatamente.

## Problem to solve <br>

One or more philosophers are sitting at a round table doing one of three things:
eating, thinking, or sleeping. <br>
• While eating, they are not thinking or sleeping, while sleeping, they are not eating
or thinking and of course, while thinking, they are not eating or sleeping.<br>
• The philosophers sit at a circular table with a large bowl of spaghetti in the center.<br>
• There are some forks on the table.<br>
• As spaghetti is difficult to serve and eat with a single fork, it is assumed that a
philosopher must eat with two forks, one for each hand.<br>
• The philosophers must never be starving.<br>
• Every philosopher needs to eat.<br>
• Philosophers don’t speak with each other.<br>
• Philosophers don’t know when another philosopher is about to die.<br>
• Each time a philosopher has finished eating, he will drop his forks and start sleeping.<br>
• When a philosopher is done sleeping, he will start thinking.<br>
• The simulation stops when a philosopher dies.<br>
• Each program should have the same options: number_of_philosophers time_to_die
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat].<br>
• number_of_philosophers: is the number of philosophers and also the number of forks <br>
• time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’
milliseconds after starting his last meal or the beginning of the simulation, it dies <br>
• time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks. <br>
• time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping. <br>
• number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ 
the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher<br>

Um ou mais filósofos estão sentados em uma mesa redonda fazendo uma das três coisas: comendo, pensando ou dormindo.<br>
• Enquanto comem, eles não estão pensando ou dormindo, enquanto dormem, eles não estão comendo ou pensando e, claro, enquanto pensam, eles não estão comendo ou dormindo.<br>
• Os filósofos sentam-se a uma mesa circular com uma grande tigela de espaguete no centro.<br>
• Existem alguns garfos na mesa.<br>
• Como o espaguete é difícil de servir e comer com um único garfo, presume-se que um o filósofo deve comer com dois garfos, um para cada mão.<br>
• Os filósofos nunca devem passar fome.<br>
• Todo filósofo precisa comer.<br>
• Os filósofos não falam uns com os outros.<br>
• Os filósofos não sabem quando outro filósofo está para morrer.<br>
• Cada vez que um filósofo termina de comer, ele larga os garfos e começa a dormir.<br>
• Quando um filósofo termina de dormir, ele começa a pensar.<br>
• A simulação para quando um filósofo morre.<br>

## Badge
<img src="philosophers.png">

## Skills
- Unix
- Imperative programming
- Rigor

## My grade
<img src="grade_philosophers.png">

## Flowchat:
<img src="philo.png">


🚧 project:<br/>

## Access the folder philo for the program that uses threads and mutex
cd philo

## Compile the program with
make

## Run the program
./philo 5 800 200 200 7 

## Clean output objects with
philo$ make fclean

:shower: Clean Obj files:<br/>

philo$ make clean

:shower: :shower: Clean All (obj files + binary):<br/>

philo$ make fclean

:shower: :shower: 🚧 Clean All + build:<br/>

philo$ make re 

<br/>See Makefile<br/>

### Made with: <br/>

### Alexandre Zamarion
<div style="display: inline_block">
 <a href="https://github.com/alezamarion" target="_blank"><img align="center" alt="Github_Jorge" height="30" width="30" src="https://cdn-icons-png.flaticon.com/128/1051/1051275.png" target="_blank"></a>
 <a href="https://www.linkedin.com/in/alexandre-zamarion-cepeda-a3766323a/" target="_blank"><img align="center"src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a> 
</div>

### Jorge Alves
<div style="display: inline_block">
 <a href="https://github.com/jorgeedualves/jorgeedualves" target="_blank"><img align="center" alt="Github_Jorge" height="30" width="30" src="https://cdn-icons-png.flaticon.com/128/1051/1051275.png" target="_blank"></a>
 <a href="https://www.linkedin.com/in/jorge-eduardo-alves-094b4331/" target="_blank"><img align="center"src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a> 
</div>


