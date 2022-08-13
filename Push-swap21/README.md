# Push-swap21

"This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting."

<img width="213" alt="Screenshot 2022-08-13 at 07 11 23" src="https://user-images.githubusercontent.com/80685686/184467962-95ee6b00-4ea0-4f68-979c-896f1a3967eb.png">

To generate push_swap program:
```
make  
```
To clean all:
```
make fclean
```

To run visualizer:
```
python3 python_visualizer.py `ruby -e "puts (-10..50).to_a.shuffle.join(' ')"`
```
![ezgif com-gif-maker](https://user-images.githubusercontent.com/80685686/184468550-3433ce72-3dcd-47f0-a892-e728f9dd2f4e.gif)

To check leaks: 
```
leaks -atExit -- ./push_swap 2 7 8 4    
```
