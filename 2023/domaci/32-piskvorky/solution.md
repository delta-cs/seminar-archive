# Piškvorky – řešení

Programu začíná načtením rozměrů hrací plochy, počtu tahů a začínajícího hráče. Následuje
inicializace 2D pole pro hrací plochu a `for` cyklus, který zpracovává jednotlivé tahy.

Když je tah v aktuálním průchodu neplatný, program to oznámí a rovnou se ukončí. V opačném případě se symbol vloží na
hrací plochu, a pokud tento tah vedl k výhře některého z hráčů, program vypíše vítězného hráče a číslo vítězného tahu.

Funkce IsWin provádí kontrolu, zda aktuální tah vedl k výhře. Prochází horizontální, vertikální a obě diagonální směry
od aktuálního tahu a počítá počet symbolů v řadě. Pokud někde narazí na požadovaný počet symbolů (SymbolWinCount), vrátí
hodnotu true. Funkce HasCoordinates zajišťuje, že se kontrola neprovede mimo hrací plochu.

Funkce `IsWin` přijímá několik parametrů – pole reprezentující hrací plochu a souřadnice aktuálního tahu – a provádí
kontrolu, zda daný tah vedl k výhře.

Funkce začíná deklarací čtyř pomocných proměnných, které slouží jako počítadla symbolů v řadě ve všech možných směrech –
horizontálním, vertikálním a obou diagonálních. Následuje `for` cyklus, který postupně prochází políčka kolem souřadnic
zadaného tahu. Výhodou je, že cyklus nemusí procházet celé pole, nýbrž stačí pouze políčka vzdálená nejvýše 5 (tj. počet
uložený v konstantě) pozic od právě umístěného symbolu. S jinými políčky se totiž tento symbol ani spojit nemohl. V
rámci cyklu jsou vyhodnocovány všechny čtyři směry. V každém kroku se aktualizují souřadnice x a y podle aktuální
hodnoty `i` a s použitím pomocné funkce se provádí kontrola, zda nevyjdou mimo hrací plochu. Jsou-li v platném rozsahu a
obsahují stejný symbol jako je na pozici právě zahraného tahu, je příslušné počítadlo zvýšeno. V opačném případě je
počítadlo resetováno na nulu.

Funkce průběžně provádí kontrolu ve všech směrech, a když některý směr obsahuje požadovaný počet symbolů v řadě, vrátí
`true`, tedy, že zahraný tah vedl k výhře. Nebyl-li ani v jednom směru tento počet dosažen, vrátí funkce
nakonec `false`.

Když nebylo během cyklu v hlavní části programu dosaženo neplatného tahu ani výhry, vypíše se (podle zadání) otazník.
