def is_free(person, people):
  return people[person][1] == None

def ranking(p1, pp1, p2):
  return pp1[p1][0].index(p2)

#get highest-ranked not-yet-proposed-to possible partner
def get_possible_partner(person, people):
  person_value = people[person]
  for poss_partner in person_value[0]:
    if poss_partner not in person_value[2]:
      return poss_partner

  return None

def gale_shapley(women, men):
  #invariant: only free women in free_women list
  free_women = list(women.keys())

  while len(free_women) > 0:
    #extract 0-th free woman
    woman = free_women[0]
    man = get_possible_partner(woman, women)
    women[woman][2].append(man)
    if is_free(man, men):
      women[woman][1] = man
      free_women.pop(0)
      men[man][1] = woman
    #rank is better if smaller
    elif ranking(man, men, woman) < ranking(man, men, men[man][1]):
      #past_partner is man's current partner, who has worse ranking
      past_partner = men[man][1]
      women[past_partner][1] = None
      #add abandoned woman to free_women
      free_women.append(past_partner)
      women[woman][1] = man
      free_women.pop(0)
      men[man][1] = woman

#3rd list: already proposed-to person
w = {'wanda':[['brent','hank','oscar','davis'],None,[]],
     'emma':[['davis','hank','oscar','brent'],None,[]],
     'lacey':[['brent','davis','hank','oscar'],None,[]],
     'karen':[['brent','hank','davis','oscar'],None,[]]
    }

m = {'oscar':[['wanda','karen','lacey','emma'],None,[]],
     'davis':[['wanda','lacey','karen','emma'],None,[]],
     'brent':[['lacey','karen','wanda','emma'],None,[]],
     'hank':[['lacey','wanda','emma','karen'],None,[]]
    }

gale_shapley(w, m)
for woman in w.keys():
  print(woman, '-', w[woman][1])
print()
for man in m.keys():
  print(man, '-', m[man][1])
