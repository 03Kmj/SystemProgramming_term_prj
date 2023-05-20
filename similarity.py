import difflib

main_contents = 'printf("Hello World!\n");'
sub_contents = 'fprintf("hello world?\n");)'

main_bytes = bytes(main_contents, 'utf-8')
sub_bytes = bytes(sub_contents, 'utf-8')
main_bytes_list = list(main_bytes)
sub_bytes_list = list(sub_bytes)

sm = difflib.SequenceMatcher(None, main_bytes_list, sub_bytes_list)
similar = sm.ratio() * 100

print(round(similar, 2), "%")
