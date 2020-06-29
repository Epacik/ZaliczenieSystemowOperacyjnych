Zmienia pozycję w pliku opisanym podanym deskryptorem na kilka możliwych sposobów oznaczonych flagami




SEEK_SET - Offset jest ustawiany na taki jaki podaliśmy w argumencie względem początku pliku. 

Np.: jeśli obecny offset to 3 i do funkcji przekażemy 3 to to offset zostanie ustawiony na 3.


SEEK_CUR - Offset jest ustawiany na obecny względem obecnego <br />Np.: jeśli obecny offset to 3 i do funkcji przekażemy 3 to to offset zostanie ustawiony na 6


SEEK_END - Offset jest ustawiany na całkowitą wielkość pliku plus podany offset.
    Np.: jeśli plik ma długość 6 i do funkcji przekażemy 3 to offset zostanie ustawiony na 9, 3 bajty po zakończeniu pliku.<br />
SEEK_DATA - Ustawia offset pliku na następny fragment zawierający dane znajdujący się w odległości większej lub równej do przekazywanego offsetu, jeśli obecc offset wskazuje na dane, to offset nie zostaje zmieniony.

SEEK_HOLE - Ustawia offset pliku na następny fragment nie zawierający danych znajdujący się w odległości większej lub równej do przekazywanego offsetu, jeśli obecc offset wskazuje na dane, to offset nie zostaje zmieniony.





Lseek pozwala na ustawienie offsetu poza wielkość pliku na dysku, co jednak nie zmienia wielkości pliku.


Jeśli dane zostaną zapisane do takiego offsetu to dziura pomiędzy poprzednim końcem pliku a nowymi danymi zostanie wypełniona znakami \0

Zwraca nowy offset pliku w przypadku pomyślnej zmiany lub -1 w przypadku błędu.
