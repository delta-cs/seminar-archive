# Abecední pořadí – řešení

Řešení stojí na funkci `areWordsInOrder`, která zjišťuje, zda jsou dvě předaná slova ve správném pořadí. Poslední
parametr určuje, zda mají být seřazena abecedně sestupně či vzestupně. Používá dvě pomocné proměnné:

- zda jsou slova správně seřazena podle velikosti písmen a
- zda je stav předchozí proměnné již definitivní nebo teprve dočasný.

Cyklus prochází písmena od začátku do délky kratšího ze slov. Když jsou odlišná, zjistí se, zda splňují pořadí v
abecedě, a výsledek se rovnou vrátí. V opačném případě zbývá určit, zda jsou ve správném pořadí, co se velikosti písmen
týče. Pokud je to ale již rozhodnuto (to značí druhá pomocná proměnná), jde se dál. To zajišťuje, že pořadí velikosti
písmen se již nemůže změnit, protože jakmile se najde písmeno na nějaké pozici, kvůli kterému má jedno slovo přednost,
písmena na dalších pozicích již nehrají roli.

Když nedošlo k vrácení během cyklu, musí k němu dojít po skončení. Jsou-li slova jinak dlouhá, vrátí se, zda je první
kratší (má mít přednost) než druhé. Jinak už záleří jen na tom, zda jsou slova správně seřazena podle velikosti písmen.

V hlavní části programu se cyklem prochází všechna slova a každé dvě vedle sebe se funkcí porovnají. K porovnání dochází
v obou směrech – sestupně i vzestupně. Pakliže je už rozhodnuto, zda mají být slova řazena sestupně, a zároveň v tomto
pořadí nejsou, ihned se to vypíše a program končí. Když o směru ještě rozhodnuto není, pak se zjištuje, zda jsou
seřazena aspoň v nějakém z nich. Tento směr se poznamená do logické proměnné a zároveň se poznačí, že o něm bylo
rozhodnuto. Když ani jeden ze směrů ale neplatí, je vypsáno nesprávné pořadí a program končí.
