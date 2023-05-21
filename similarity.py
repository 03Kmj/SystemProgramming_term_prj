import difflib
import sys

main_file = sys.argv[1]
sub_file = sys.argv[2]

main_contents = open(main_file, 'r').read()
sub_contents = open(sub_file, 'r').read()

main_bytes = bytes(main_contents, 'utf-8')
sub_bytes = bytes(sub_contents, 'utf-8')
main_bytes_list = list(main_bytes)
sub_bytes_list = list(sub_bytes)

sm = difflib.SequenceMatcher(None, main_bytes_list, sub_bytes_list)
similar = sm.ratio() * 100

with open('similarity.txt', 'w') as f:
    f.write((round(similar, 2)))
