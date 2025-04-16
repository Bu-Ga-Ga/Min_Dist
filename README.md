# Программа для вычисления расстояния между многоугольниками

Программа анализирует взаимное расположение двух многоугольников, вычисляя минимальное расстояние между ними и проверяя их пересечение.

## Алгоритм работы
- Чтение данных:
    - Считывание количества точек и координат для каждого многоугольника
    - Сохранение в динамические массивы структур Point
- Проверка пересечений:
    - Для каждой пары ребер из разных многоугольников проверяется пересечение с помощью функции halfplane
    - Если найдено пересечение - выводится сообщение и программа завершается

- Вычисление минимального расстояния:
    - Между всеми парами точек из разных многоугольников
    - Между точками одного многоугольника и ребрами другого (с учетом типа треугольника)

- Вывод результатов:
    - Если многоугольники касаются в одной точке (расстояние ≈ 0)
    - Иначе - минимальное расстояние между ними
## Ограничения
- Программа работает только с простыми многоугольниками (без самопересечений)

