# Horolezec

## Zadání
Adéla se rozhodla zúčastnit turistické soutěže, ve které musí spočítat trasu, kterou ušla. Její cesta vede nahoru a dolů po horách, přičemž každá část cesty je charakterizována:
- **rozdílem úhlu sklonu** (rozdíl od posledního úhlu ve stupních, kladný úhel značí stoupání, záporný úhel značí klesání),
- **délkou úseku** (přepona trojúhelníku).

Cílem je spočítat:
1. **Celkovou výšku hory** od základny po nejvyšší bod, kterou Adéla dosáhne během své cesty.
2. **Celkovou vzdálenost pohledem shora** (vodorovnou vzdálenost, jako kdybychom cestu promítli na mapu).

---
## Nápověda:

Představte si každý úsek jako přeponu pravoúhlého trojúhelníku s daným úhlem vzhledem k vodorovné rovině.

Pro výpočet použijte goniometrické funkce (sin a cos).

- **Změna výšky na daném úseku:**  
  `deltaVyska = sin(úhel) * délka_úseku`

- **Vodorovná vzdálenost na daném úseku:**  
  `deltaVodorovne = cos(úhel) * délka_úseku`

Pozor ve většině programovací jazycích pracuje sinus a cosinus s radiány místo stupni.
```
radiany = stupne * (π/180)
```


Tolerance u výsledku je ± 0.01

**Poznámka:** Dejte pozor na znaménko úhlu. Kladný úhel znamená stoupání, záporný klesání.

---

## Vstup
Na vstupu je postupně zadán:
- Celý počet `n` (1 <= `n` <= 1000), což je maximální počet zlomů (změn sklonu) cesty.
- `n` řádků dvojic hodnot:
    - celé číslo `U`(-90 <= `U` <= 90) – úhel sklonu úseku ve stupních,
    - reálné číslo `L` (1 <= `L` <= 10^4) – délka přepony (úseku) v metrech.

---

## Výstup
Program vypíše dvě hodnoty:
1. **Celkovou výšku hory `H`** – nejvyšší dosaženou výšku od základny, zaokrouhlenou na dvě desetinná místa.
2. **Celkovou vodorovnou vzdálenost `D`** – celkovou prošlou vodorovnou vzdálenost do okamžiku, kdy se Adéla vrátila na počáteční výšku, také zaokrouhlenou na dvě desetinná místa.

Výstupní formát:
```
<max výška>
<vodorovná vzdálenost>
```

## Příklady
1)
```
3
30 40
10 50
-90 80
```
2)
```
28.68
83.88
```