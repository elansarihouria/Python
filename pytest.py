import fputs
import unittest
import sys
class TestFputs (unittest.TestCase):


	def test_copy_data(self):
		content_to_copy="Testing Module! ohhhhhhhh  it work !!"
		bytes_copied = fputs.fputs(content_to_copy,"write.txt")

		with open("write.txt",'r') as f:
			content_copied=f.read()

		self.assertEqual(content_copied , content_to_copy)

