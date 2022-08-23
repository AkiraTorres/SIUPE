import turtle
t = turtle.Pen()
colors = ['red', 'blue', 'green', 'yellow']

for x in range(100):
    t.pencolor(colors[x%4])
    t.forward(x)
    t.left(225)

turtle.Screen().exitonclick()