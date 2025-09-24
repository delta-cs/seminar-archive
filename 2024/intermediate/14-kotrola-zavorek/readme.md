# Kontrola Závorek

Tomášovi se v editoru, který používá pro programování rozbila kontrola správnosti syntaxe jazyků.

Tomáš je chytrý a tuto vymoženost většinou nepotřebuje ale jednou za čas, když píše programy s hodně závorkama se ztratí a udělá chybu.

Vaším úkolem je napsat program pro kontrolu správnosti závorek v programu.



## Vstup
- Na standardní vstup dostanete text, který máte zkontrolovat
- Vsup čtěte až do konce (`EOF`)
- Na vstupu můžou být kromě závorek jakékoli znaky, ty má program ignorovat


## Co musí progam kontrolovat
- Máme 3 typy závorek - `(` `)`, `[` `]`, `{` `}`

- Každá otevírací závorka musí mít k sobě právě 1 uzavírací závorku stejného typu

- Uzavírací závorka musí být na stejné úrovni jako otevírací. \
    *př.: `( { ) }` není validní, otevírací `(` je venku, tedy na jiné úrovni než `)`*



## Výstup
- Pokud progam nenašel chybu, vypíše `VALID`
- Pokud nějakou chybu našel, vypíše `INVALID`


## Příklady
1)
```
({)}
```
```
INVALID
```

2)
```
int main(){
    int a[10];
}
```
```
VALID
```

3)
```
def hi():
    return []]
```
```
INVALID
```