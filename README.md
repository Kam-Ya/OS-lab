
# Operating Systems Design Lab

1. Lab1 **Process Management**
    - Analytical questions and answers covered
    - 5 programming questions:
        1. Use the "top" command to display process information (store this in log.txt)
        2. Usecommands to kill any running libreoffice instance, explain the commands used
        3. Write a program to open an instance of libre office than kill it
        4. Write a program to monitor running processes and kill any instance of libreoffice it comes across
        5. Write a program to monitor running processes and kill any process using more than 200Kb of memory or 3+ minutes of CPU time
      
    I failed to properly implement program number 5, I realize now that I was over complicating the question  
    I tried to use the /proc file system to see all processes and get information about them. I should have used the "ps" command and run that into a text file which I could then have read from.  
    This would have been a better and simpler approach. I should have used this approavh to make the other programs as well.  
    Other than my failure to achieve the goal I do not regret how this lab turned out as I found it very educational.
2. Lab2 **Scheduling**
    - Analytical questions and answers covered
    - 1 programming question:
        1. Design and implement a multi-level queue with priority levels 1, 2, and 3. Give system processes a higher priority than user processes, consider processes to have fixed priority