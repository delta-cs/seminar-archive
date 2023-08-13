# 2. Lámání textu

Ve vstupu programu bude zadáno:

1. povolená délka řádku `d` (celé číslo)
2. počet řádků vstupu `r`
3. prázdný řádek
4. `r` řádků vstupního textu.

Vaším úkolem je „přelámat“ text tak, aby dodržoval povolenou délku řádku. To znamená:

- Dávejte slova za sebe na řádek.
- Pokud by text přesáhl i s dalším slovem povolenou délku, zapíše se toto slovo na další řádek.
    - Pokud je nějaké slovo delší než povolená délka `d`, dejte ho na řádek samotné. Výjimkou je následující pravidlo.
- Zalomení řádky nikdy nesmí přijít za neslabičnou předložkou (k, s, v, z), ať je velká nebo malá. Při přetečení se
  předložka musí s dalším slovem nacházet až na dalším řádku.
    - A to i v případě, že po ní následuje slovo, které je samo delší, než povolená délka `d`. I takové slovo bude na
      řádku s předložkou.
- Nekončete řádky mezerami.
- Zalomení řádky v původním textu chápejte jako obyčejnou mezeru.
    - Dvě zalomení po sobě (prázdný řádek) však ponechte nezměněné - znamenají nový odstavec.

Pozor, vstupní text může být **opravdu** dlouhý.

Pokud váš program nebude připravený na kódování českých znaků (UTF-8), nevadí - ztratíte jen malou část bodů.

Každý řádek výstupu (i ten poslední) musí být zakončen znakem nové řádky (`\n`).

## Příklad #1

### Vstup
```
25
9

Když se to narodilo, bylo to jenom takové bílé nic, do
hrsti se to vešlo; ale anžto to mělo pár černých ušisek
a vzadu ocásek, uznali jsme, že to je psisko, a protože
jsme si přáli mít psí holčičku, dali jsme tomu jméno
Dášeňka.

Dokud to bylo bílé nic, bylo to slepé, bez očí, a co se
nožiček týče, inu, mělo to dva páry čehosi, čemu se při
dobré vůli mohlo říkat nožičky, a k tomu i jeden čumáček. 
```

### Výstup
```
Když se to narodilo, bylo
to jenom takové bílé nic,
do hrsti se to vešlo; ale
anžto to mělo pár černých
ušisek a vzadu ocásek,
uznali jsme, že to je
psisko, a protože jsme si
přáli mít psí holčičku,
dali jsme tomu jméno
Dášeňka.

Dokud to bylo bílé nic,
bylo to slepé, bez očí, a
co se nožiček týče, inu,
mělo to dva páry čehosi,
čemu se při dobré vůli
mohlo říkat nožičky, a 
k tomu i jeden čumáček.
```

## Příklad #2

### Vstup

```
10
3

Mexický Popocatépetl
se řadí k nejznámějším
sopkám na světě.
```

### Výstup

```
Mexický
Popocatépetl
se řadí
k nejznámějším
sopkám na
světě.
```

### Vysvětlení

Slovo `Popocatépetl` je delší, než povolených 10 znaků, a proto se nachází na řádku samotné.

Slovo `nejznámějším` limit také přesahuje, ale jelikož jej předchází neslabičná předložka `k`, je na řádku s ní.
