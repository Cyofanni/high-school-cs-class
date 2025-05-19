def lex_rel(s1, s2, i, l1, l2):
    if l1 == 0 and l2 == 0:
        return "eq"
    if l1 == 0 and l2 != 0:
        return "lt"
    if l2 == 0:
        return "gt"
    if ord(s1[i]) < ord(s2[i]):
        return "lt"
    if ord(s1[i]) > ord(s2[i]):
        return "gt"
    if s1[i] == s2[i]:
        return lex_rel(s1, s2, i + 1, l1 - 1, l2 - 1)

def lex_rel_iter(s1, s2, l1, l2):
  i = 0
  while l1 > 0 and l2 > 0:
    if ord(s1[i]) < ord(s2[i]):
      return "lt"
    elif ord(s1[i]) > ord(s2[i]):
      return "gt"
    i += 1
    l1 -= 1
    l2 -= 1

  if l1 == 0 and l2 > 0:
    return "lt"
  elif l1 > 0 and l2 == 0:
    return "gt"
  return "eq"

s1 = input()
s2 = input()
print(lex_rel(s1, s2, 0, len(s1), len(s2)))
print(lex_rel_iter(s1, s2, len(s1), len(s2)))
