# Obraz – řešení

Na začátku programu se definují čtyři konstanty, které číselně označují čtyři hrany rámu. Zároveň se konstantou definuje
znak šroubu a počet šroubů ve vrchní hraně obrazu.

V hlavní části programu se obraz načte do 2D pole a následně předá funkci, která má za úkol zjistit, která hrana rámu
má být při zavěšení nahoře. Drží si proměnnou pro počet nalezených šroubů. Začíná kontrolou levé hrany, tedy `for`
cyklem, který prochází všechny řádky a na každém kontroluje, zda se je jeho první znak šroub. Pokud ano, zvýší
počítadlo. V případě, že počítadlo přesáhlo požadovaný počet šroubů, může funkce vrátit konstantu znamenající levou
hranu. Když se to v celém cyklu nestane, počítadlo se obnoví na nulu a pokračuje se pravou, popřípadě až vrchní hranou.
Když funkce ani po třech kontrolách nevrátí hodnotu, víme, že rám má dva šrouby na spodní straně a můžeme to rovnou
vrátit.

Vrácená hodnota je spolu s 2D polem obrazu předána druhé funkci, která jej vykreslí otočen právě tak, jak je jí v
parametru zadáno. `switch` podle kýženého natočení obrazu vybírá vždy dva vnořené `for` cykly, které 2D pole prochází ve
správném směru. Při zavěšení na levé nebo pravé hraně jsou svislítka nahrazena spojovníky a naopak, protože obraz je
otočen o 90 stupňů. Ale pozor, tato záměna se provádí pouze na indexech, které jsou na okrajích, tedy 0 nebo rozměr
pole - 1. Při zavěšení na vrchní hraně je výpis stejný, jako byl vstup programu – obraz se nijak neotáčí.
