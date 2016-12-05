def jsonify(string):
	lines = []
	for line in string:
		lines.append(line)

	count = int(lines[0].split(" ")[2])
	attr = {}
	for i in range(1, count):
		if i <= 9:
			try:
				attr[lines[4+i].split(' ')[4]] = int(lines[4+i].split(' ')[25], 16)
			except ValueError:
				attr[lines[4+i].split(' ')[4]] = 0
		else:
			try:
				attr[lines[4+i].split(' ')[3]] = int(lines[4+i].split(' ')[26], 16)
			except ValueError:
				attr[lines[4+i].split(' ')[3]] = 0

	return attr



d = jsonify(open("attr.txt", "r"))