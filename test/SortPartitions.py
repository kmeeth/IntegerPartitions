def reverse_string(string):
    parts = string.split(" ")
    res = ""
    for p in reversed(parts):
        res += p + ' '
    return res[2:] + '\n'

def sort_lines(input_file, output_file):
    # Read lines from input file
    with open(input_file, 'r') as f:
        lines = f.readlines()

    # Sort the lines
    if input_file == "conj.int":
        lines = [reverse_string(line) for line in lines]
    lines.sort()

    # Write sorted lines to output file
    with open(output_file, 'w') as f:
        for line in lines:
            f.write(line)

if __name__ == "__main__":
    files = ["back.int", "conj.int", "tree.int", "back.set", "filt.set"]

    for file in files:
        sort_lines(file, file)

    print("Lines sorted successfully!")