def parse(path):
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

	from os import listdir
	from subprocess import Popen, PIPE
	from json import dump
	files = listdir(path)
	data = {}
	i = 1
	for filename in files:
		command = "readelf -SW %s" % path+filename
		data[i] = jsonify(Popen(command, shell=True, stdout=PIPE).stdout)
		i += 1

	dump(data, open("data.json", "w"))



from sys import argv
parse(argv[1])