from typing import List


def divide_path(path: str) -> List[str]:
    path_split = path.split("/")
    path_is_absolute = path.startswith("/")

    path_simplified = []
    i = 1 if path_is_absolute else 0
    while i < len(path_split) - 1:
        segment = path_split[i]

        if path_is_absolute and segment == "..":
            if len(path_simplified) < 1:
                i += 1
                continue

            path_simplified.pop()
        else:
            path_simplified.append(segment)

        i += 1

    return path_simplified


if __name__ == "__main__":
    path1 = input()
    path2 = input()

    path2_is_absolute = path2.startswith("/")

    path1_segments = divide_path(path1)
    path2_segments = divide_path(path2)

    result = ""

    if path2_is_absolute:
        longer_path_length = max(len(path1_segments), len(path2_segments))
        i = 0
        while i < longer_path_length:
            if i < len(path1_segments) and i < len(path2_segments) and path1_segments[i] == path2_segments[i]:
                i += 1
                continue

            j = i
            while j < len(path1_segments):
                result += "../"
                j += 1

            j = i
            while j < len(path2_segments):
                result += path2_segments[j] + "/"
                j += 1

            break
    else:
        for segment in path2_segments:
            if segment == "..":
                if len(path1_segments) < 1:
                    continue

                path1_segments.pop()
            else:
                path1_segments.append(segment)

        result = "/"
        for segment in path1_segments:
            result += segment + "/"

    print(result)
