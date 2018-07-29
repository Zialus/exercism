hello_world('Hello World!').
hello_world(Name,Output):- atomic_list_concat(['Hello ', Name, '!'], Output).
