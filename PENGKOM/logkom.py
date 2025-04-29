from itertools import product

def truth_table():
    print("p | q | r | \u00acq | \u00acp | \u00acr | p -> \u00acq | \u00acr -> p | (p -> \u00acq) <-> (\u00acr -> p)")
    print("-" * 80)
    
    for p, q, r in product([True, False], repeat=3):
        not_q = not q
        not_p = not p
        not_r = not r
        p_imp_not_q = not p or not_q  # p -> ¬q
        not_r_imp_p = not_r or p  # ¬r -> p
        equivalence = p_imp_not_q == not_r_imp_p  # (p -> ¬q) <-> (¬r -> p)
        
        print(f"{int(p)} | {int(q)} | {int(r)} |  {int(not_q)}  |  {int(not_p)}  |  {int(not_r)}  |    {int(p_imp_not_q)}    |    {int(not_r_imp_p)}   |        {int(equivalence)}")

truth_table()
