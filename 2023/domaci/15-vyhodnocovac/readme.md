# Vyhodnocovač

Na vstupu programu bude (na samostatných řádcích)

- celé číslo `n` (od 1 do 10 000),
- `n` řádků, na každém desetinné číslo (-10 000 až 10 000). Mezi každými dvěma těmito řádky budou vloženy řádky s jedním matematickým zaménkem:
    - `+` – plus
    - `-` – minus
    - `*` – krát
    - `/` – děleno
    - `^` – umocnění

Úkolem je vypsat hodnotu vstupního výrazu.

Znaménka mají přednost stejnou jako v matematice:

1. mocnění
2. násobení a dělení
3. sčítaní a odčítání

V případě několika operací se stejnou předností v řadě se výpočty vykonávají vždy zleva doprava, čili

- `4 / 2 / 2` = `(4 / 2) / 2` = `2 / 2` = `1`
- `2 ^ 3 ^ 2` = `(2 ^ 3) ^ 2` = `8 ^ 2` = `65`

Pokud by se ve výrazu nacházelo dělení nulou (které není v matematice definováno), program vypíše `undefined`.

## Příklad #1

### Vstup

```
4
1
+
4
*
2
^
3
```

### Výstup

```
33
```
