# Kontrola pravopisu – řešení

Založí se množina (ne pole, kvůli rychlosti vyhledávání) a naplní se slovy ze slovníku. Zároveň se připraví dvě pomocné
logické proměnné: zda aktuálním slovem začíná nová věta a zda bylo předchozí slovo číslem.

Pak přichází cyklus, který zpracovává všechny řádky vstupního textu. V průchodu vždy založí tři pole pro pravopisné
chyby:

- jejich počáteční indexy v daném řádku,
- délky jejich chybných úseků,
- příslušné hlášky.

Vznikají další dvě vnitřní pomocné proměnné: index aktuálně zpracovávaného znaku a zda byly minulé znaky součástí
sekvence duplicitních mezer.

Začnou se zpracovávat všechna slova na řádku.

Když je slovo prázdné, znamená to duplicitní mezeru. Když je první v řadě, přidá se chyba do všech výše zmíněných polí a
označí se tento stav v pomocné proměnné. Kdyby ale už tato proměnná označena byla, nevytvoří se nová chyba, ale jen se
zvýší délka té poslední. Když slovo prázdné není, proměnná se obnoví.

Když je slovo číslem a delší než 3 znaky, přidá se hláška o chybném formátování.

Když slovník neobsahuje slovo s počátečním velkým ani malým písmenem, jde o neznámé slovo.

Když nezačíná nová věta, předchozí slovo nebylo číslo, slovník aktuální slovo nezná, a přesto začíná velkým písmenem, je
to chyba.

Když slovo začíná malým písmenem a zároveň začíná věta nebo slovník toto slovo nezná, je to chyba.

Na konci slovního cyklu se přenastaví index aktuálního znaku a určí se, zda příštím slovem začíná nová věta a poznamená
se, jestli bylo toto slovo číslem.

Následuje cykus pro výpis podtržení chybných úseků pomocí indexů a délek uložených v polích.

Nakonec se vypíší hroty šipek a pod nimi jejich svislé a vodorovné čáry s hláškami.
