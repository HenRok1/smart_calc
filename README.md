# Information
Реализация калькулятора на основе Польской нотации с использованием QT.
- Программа разработана на языке Си стандарта C11 с использованием компилятора gcc и, дополнительных библиотек и модулей QT
- Программа разработана в соответствии с принципами структурного программирования
- Код выполнен в соотвествии Google Style
- Полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check
- Реализация с графическим пользовательским интерфейсом, на базе GUI-библиотеки с API - Qt
- На вход программы могут подаваться как целые числа, так и вещественные числа, записанные через точку.
- Вычисление производится после полного ввода вычисляемого выражения и нажатия на символ `=`
- Вычисление произвольных скобочных арифметических выражений в инфиксной нотации
- Вычисление произвольных скобочных арифметических выражений в инфиксной нотации с подстановкой значения переменной _x_ в виде числа
- Построение графика функции, заданной с помощью выражения в инфиксной нотации с переменной _x_  (с координатными осями, отметкой используемого масштаба и сеткой с адаптивным шагом)
- Для построения графиков функции необходимо дополнительно указывать отображаемые область определения и область значения
- Проверяемая точность дробной части - 7 знаков после запятой

## Дополнительные функции:
Специальный режим "кредитный калькулятор":
- Вход: общая сумма кредита, срок, процентная ставка, тип (аннуитетный, дифференцированный)
- Выход: ежемесячный платеж, переплата по кредиту, общая выплата

Специальный режим "калькулятор доходности вкладов":
 - Вход: сумма вклада, срок размещения, процентная ставка, налоговая ставка, периодичность выплат, капитализация процентов, список пополнений, список частичных снятий
 - Выход: начисленные проценты, сумма налога, сумма на вкладе к концу срока

# Installation:
```
cd src 
make all 
make build
```
