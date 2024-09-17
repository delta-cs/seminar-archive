# Mateřský programovací jazyk – řešení

Založí se asociativní pole ukládající pod názvem proměnné její hodnotu. Ze vstupu se načte kód do dvou paralelních polí:

- řádky rozdělené na slova,
- jejich úrovně zanoření v kódu.

Dále jsou vytvořeny tři pomocné proměnné:

- zda probíhá opakování nějakého cyklu,
- index prvního řádku tohoto cyklu,
- aktuální úroveň zanoření.

Následuje cyklus, který má za cíl všechny řádky programu vykonat.

Když je řádek zanořený hlouběji než aktuální vykonávaná úroveň, znamená to, že je v podmínce či cyklu, která neprobíhá,
a může se tak přeskočit. Pakliže je zanořený méně, tak se z nějaké aktuálně vykonávané podmínky či cyklu právě vystupuje
ven. V případě cyklu se index vykonávaného řádku `i` přesune na řádek s podmínkou tohoto cyklu, aby došlo (je-li
splněna) k opakování.

Vykonávání využívá dvě funkce: `expressionValue` vyhodnotí početní výraz. Projde v něm všechny členy a v případě
proměnné začte její hodnotu z asociativního pole. Člen pak podle předchozího znaménka přičte či odečte od celkového
výsledku, který nakonec vrátí. `conditionPass` určí, zda je logický výraz platný či nikoli. Pomocí
operátorů `rovno`, `aspon` a `nejvic` porovnává extrahované početní výrazy, jejichž výsledky
vypočítává `expressionValue`. Obě tyto funkce vrací dvě hodnoty naráz: logickou proměnnou, zda je vstupní výraz
validní (tedy nedošlo v něm k chybě) a samotný výsledek funkce.

Vykonávací cyklus v hlavní části programu pracuje takto:

- V případě splnění podmínky v `kdyz` dojde ke zvýšení úrovně zanoření.
- `dokud` provede to stejné a navíc označí v pomocné proměnné, že probíhá opakování a poznačí jeho počáteční index.
- `vypsat` jednoduše přidá do výstupního pole výsledek z `expressionValue`.
- Jiná použitá slova už musí znamenat proměnnou. V takovém případě se do asociativního pole uloží zpracovaný výraz
  z `expressionValue`.

Pokud za celou dobu nedošlo k chybě, je na konci vypsáno pole s uloženými výstupními řádky.
