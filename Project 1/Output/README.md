===== LAB EQUIPMENT RETURN TRACKER =====

1. Add Equipment
2. Display Equipment
3. Search Equipment
4. Add Return Request
5. Process Return Request
6. Delete Equipment
7. Display Action History (Stack)
8. Display Return Queue
9. Exit

Enter your choice: 1

Enter Equipment ID: 101
Enter Student ID: 205
Enter Issue Time: 10AM
Equipment added successfully!


Enter your choice: 1

Enter Equipment ID: 102
Enter Student ID: 218
Enter Issue Time: 11AM
Equipment added successfully!


Enter your choice: 2

--- Equipment Records ---
Equipment ID: 101
Student ID: 205
Issue Time: 10AM
Status: Issued

Equipment ID: 102
Student ID: 218
Issue Time: 11AM
Status: Issued


Enter your choice: 3

Enter Equipment ID to search: 101

Equipment found!
Student ID: 205
Issue Time: 10AM
Status: Issued


Enter your choice: 4

Enter Equipment ID for return: 101
Return request added to queue.


Enter your choice: 4

Enter Equipment ID for return: 102
Return request added to queue.


Enter your choice: 8

--- Return Queue (FIFO) ---
Equipment ID: 101
Equipment ID: 102


Enter your choice: 5

Equipment 101 returned successfully.


Enter your choice: 2

--- Equipment Records ---
Equipment ID: 101
Student ID: 205
Issue Time: 10AM
Status: Returned

Equipment ID: 102
Student ID: 218
Issue Time: 11AM
Status: Issued


Enter your choice: 7

--- Action History (Latest First) ---
Returned equipment 101
Added equipment 102
Added equipment 101


Enter your choice: 6

Enter Equipment ID to delete: 102
Equipment deleted successfully.


Enter your choice: 2

--- Equipment Records ---
Equipment ID: 101
Student ID: 205
Issue Time: 10AM
Status: Returned


Enter your choice: 8

--- Return Queue (FIFO) ---
Equipment ID: 102


Enter your choice: 5

Equipment 102 was deleted. Request cancelled.


Enter your choice: 7

--- Action History (Latest First) ---
Deleted equipment 102
Returned equipment 101
Added equipment 102
Added equipment 101


Enter your choice: 9

Exiting program. Thank you!
