
Contributions:

Emma: makefile, SimplePlayer, doMove

Maya: randomHeuristic, Player Constructor, all hpp files

Both brainstormed algorithm for minimax, edited the getAllMoves function, and 
created the heuristic. 


Improvements:

We began with an AI that picked the first valid move and made it. Then, to improve the AI
to make it beat random players, we added a heuristic that evaluates the strategic value
of a given coin based on its position. 
To make the AI competitive against players that considered our possible reactions to their moves,
we implemented minimax which recurses to a depth of 2, allowing our AI to minimize
the opponent's maximum gain. The minimax utilizes the heuristic that gives each coin
a strategic value based on its position on the othello board--using this scoring system and the
assumption that our opponent will want to maximize their own score, we
keep track of how well our side fares under a move we could potentially make. 

We think our minimax will perform fairly well since it is able to predict our opponent's move
and determine the best course of action to take, assuming they will maximize their score. This is
better than blindly applying the heuristic, as it only takes a single move change the winning side
at any point in the game. Thus, instead of evaluating a single move, it's better to evaluate the 
heuristic after an acculumation of possible moves.  


Ideas that were tried but didn't work:

Before using the heuristic that gives each coin a strategic value based on its position on 
the othello board, we tried a more primitive scoring approach of simply counting the amount of
coins we'd placed on the board vs the number of coins our opponent had. This was not very effective,
as the amount of coins each side has on the board is not indicative of who has the strategic advantage.
The strategic value of a given move can be determined by applying the heuristic to all coins
on the board for a given side at that point in the game, which is what we eventually designed our getBoardScore to do.  



