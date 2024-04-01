# Obliczanie_sumy
Program realizujący poniższe zadanie:
Napisz w języku ANSI C program obliczający sumę kolejnych N liczb pierwszych poczynając od M.

Program powinien sprawdzać kolejno wszystkie liczby od M wzwyż, czy nie dzielą się przez jakąkolwiek liczbę większą od 1 i mniejszą od niej samej. W przypadku gdy liczba dzieli się przez cokolwiek w tym przedziale, jej sprawdzanie powinno być natychmiast porzucane (bo nie jest pierwsza), a w przeciwnym wypadku liczba powinna być dodawana do obliczanej sumy, i licznik znalezionych liczb pierwszych powinien być inkrementowany. Procedura zatrzymuje się gdy ten licznik osiągnie zadaną wartość N, która powinna być odczytywana jako pierwszy argument wywołania programu, i suma powinna być wyświetlona na wyjściu.
by przyspieszyć działanie programu wykorzystując wielordzeniowy procesor komputera, zamień program na wielowątkowy.

Program powinien utworzyć K wątków obliczeniowych, z których każdy będzie powtarzalnie wykonywał następujące kroki:

1. pobierz aktualną wartość liczby `sprawdz` i natychmiast zinkrementuj ją
2. sprawdź czy liczba `sprawdz` jest pierwsza
3. jeśli tak, to dodaj ją do `suma` i zinkrementuj `znalezione`
4. jeśli wartość `znalezione` jest równa lub większa `N` to zakończ pracę
5. w przeciwnym wypadku powtórz kroki od 1.

Liczba wątków obliczeniowych K powinna być zadana trzecim argumentem wywołania programu. Wątek główny (funkcja main) powinien czekać na zakończenie pracy wszystkich wątków obliczeniowych, po czym wyświetlać na wyjściu obliczoną sumę liczb pierwszych.
