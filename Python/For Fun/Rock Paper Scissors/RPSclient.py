# garbage code (only for GUI)

from qian0102_5A import *
import tkinter as tk


comp = RPSai()
human_wins = 0
machine_wins = 0
rounds_total = 0
ties_total = 0


def hit_event_rock():
	cpuMove = comp.playMovePro()
	comp.opponentMove("R")
	w = winner(cpuMove,"R")
	judge(var,w)
	setLabel(var_human_wins,var_machine_wins,var_ties,var_rounds_total)

def hit_event_paper():
	cpuMove = comp.playMovePro()
	comp.opponentMove("P")
	w = winner(cpuMove,"P")
	judge(var,w)
	setLabel(var_human_wins,var_machine_wins,var_ties,var_rounds_total)

def hit_event_scissor():
	cpuMove = comp.playMovePro()
	comp.opponentMove("S")
	w = winner(cpuMove,"S")
	judge(var,w)
	setLabel(var_human_wins,var_machine_wins,var_ties,var_rounds_total)

def judge(var,w):
	global human_wins, machine_wins, rounds_total, ties_total
	rounds_total += 1
	if w == 1:
		var.set("Machine win!")
		machine_wins += 1
	elif w == 0:
		var.set("Draw!")
		ties_total += 1
	else:
		var.set("You win!")
		human_wins += 1

def setLabel(var_human_wins,var_machine_wins,var_ties,var_rounds_total):
	global human_wins, machine_wins, rounds_total, ties_total
	var_human_wins.set("You wins: " + str(human_wins))
	var_machine_wins.set("Machine wins: " + str(machine_wins))
	var_ties.set("Total ties: " + str(ties_total))
	var_rounds_total.set("Total rounds: " + str(rounds_total))


window = tk.Tk()
window.title('RPS Game')
window.geometry('800x600')



var = tk.StringVar()
l = tk.Label(window, 
    textvariable=var,
    bg='green', font=('Arial', 14), width=15, height=2)
l.pack(padx=5, pady=20, side=tk.LEFT)

var_human_wins = tk.StringVar()
var_human_wins.set("You wins: 0")
l_human = tk.Label(window, 
    textvariable=var_human_wins,
    bg='yellow', font=('Arial', 14), width=15, height=2)
l_human.pack(padx=5, pady=40, side=tk.LEFT)

var_machine_wins = tk.StringVar()
var_machine_wins.set("Machine wins: 0")
l_machine = tk.Label(window, 
    textvariable=var_machine_wins,
    bg='blue', font=('Arial', 14), width=15, height=2)
l_machine.pack(padx=5, pady=60, side=tk.LEFT)

var_ties = tk.StringVar()
var_ties.set("Total ties: 0")
l_ties = tk.Label(window, 
    textvariable=var_ties,
    bg='grey', font=('Arial', 14), width=15, height=2)
l_ties.pack(padx=5, pady=80, side=tk.LEFT)

var_rounds_total = tk.StringVar()
var_rounds_total.set("Total rounds: 0")
l_round = tk.Label(window, 
    textvariable=var_rounds_total,
    bg='red', font=('Arial', 14), width=15, height=2)
l_round.pack(padx=5, pady=100, side=tk.LEFT)


# content
rock = tk.Button(window, 
	text='Rock',
	width=15, height=2, 
	command=hit_event_rock)
rock.pack(padx=10, pady=10, side=tk.TOP)

paper = tk.Button(window, 
	text='Paper',
	width=15, height=2, 
	command=hit_event_paper)
paper.pack(padx=10, pady=10, side=tk.TOP)

scissor = tk.Button(window, 
	text='Scissor',
	width=15, height=2, 
	command=hit_event_scissor)
scissor.pack(padx=10, pady=10, side=tk.TOP)


window.mainloop()
