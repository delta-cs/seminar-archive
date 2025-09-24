def is_valid_sudoku(sudoku):
    # Kontrola řádků
    for row in sudoku:
        if not is_valid_group(row):
            return False

    # Kontrola sloupců
    for col in range(9):
        column = [sudoku[row][col] for row in range(9)]
        if not is_valid_group(column):
            return False

    # Kontrola čtverců 3×3
    for box_row in range(0, 9, 3):
        for box_col in range(0, 9, 3):
            box = [
                sudoku[r][c]
                for r in range(box_row, box_row + 3)
                for c in range(box_col, box_col + 3)
            ]
            if not is_valid_group(box):
                return False

    return True


def is_valid_group(group):
    """Pomocná funkce pro kontrolu, zda skupina neobsahuje duplicitní čísla."""
    numbers = [num for num in group if num != "."]
    return len(numbers) == len(set(numbers))


# Čtení vstupu
sudoku = []
for _ in range(9):
    sudoku.append(input().split())

# Výstup
print(is_valid_sudoku(sudoku))
