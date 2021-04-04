def starting(asp, coord):
    index = 0
    for x in asp:
        coord[index].prim = x.position - x.radius
        coord[index].final = x.position + x.radius
        index = index + 1


def duplicate(asp, coord):
    position = 0
    index2 = 0
    for a in range(0, len(asp) - 1):
        for b in range(a + 1, len(asp)):
            if (asp[a].position == asp[b].position):
                if (coord[a].final > coord[b].final):
                    coord.pop(b)
                elif (coord[a].final > coord[b].final):
                    coord.pop(a)


def sorting(coord):
    for a in range(0, len(coord) - 1):
        for b in range(a + 1, len(coord)):
            if (coord[a].prim > coord[b].prim):
                tmp = coord[a]
                coord[a] = coord[b]
                coord[b] = tmp


def greedy(coord):
    index1 = 0
    minAspensors = 0

    minAspensors = minAspensors + 1
    for index1 in range(1, len(coord)):
        if (coord[index1].prim > coord[index1 - 1].final):
            print("No aspensors can be placed...")
            # f_w.write("Prim : " + str(x.prim) + " si final " + str(x.final) + "\n")
            return
        else:
            index2 = index1 - 1
            while (coord[index1].prim <= coord[index2].final):
                index1 = index1 + 1
            minAspensors = minAspensors + 1

    print(minAspensors)