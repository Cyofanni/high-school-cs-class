def compute_prefix_table(pattern):
    pat_len = len(pattern)
    pref_table = [0] * pat_len
    i = 1
    matched_pref_len = 0
    last_it_matched_ind = 0

    while i < pat_len:
        if pattern[i] == pattern[last_it_matched_ind]:
            matched_pref_len += 1
            last_it_matched_ind += 1
            pref_table[i] = matched_pref_len
        else:
            matched_pref_len = 0
            last_it_matched_ind = 0
            if pattern[i] == pattern[last_it_matched_ind]:
                matched_pref_len += 1
                last_it_matched_ind += 1
                pref_table[i] = matched_pref_len
        i += 1

    return pref_table

def knuth_morris_pratt(text, pattern):
    p = compute_prefix_table(pattern)
    text_length = len(text)
    pattern_length = len(pattern)

    i = 0
    pattern_pos = -1
    while i <= text_length - pattern_length and pattern_pos == -1:
        print(i)
        q = 0
        j = 0
        inc = 1
        is_match = True
        while j < pattern_length and is_match == True:
            if pattern[j] == text[i + j]:
                q += 1
            else:
                is_match = False
            j += 1
        if q == pattern_length:
            pattern_pos = i
        elif q > 0:
            inc = q - p[q - 1]

        i += inc

    return pattern_pos

print(compute_prefix_table('abcababcb'))
print('*', knuth_morris_pratt('abcababqwecixxxbeaaabcabababqqa', 'abcababab'))
