import unittest
import subprocess
import os

class TestCpu(unittest.TestCase):
    
    def _build():
        result = subprocess.run(['g++', '*.cpp', '-o', 'cpusim.exe'], capture_output=True, text=True)
        return result

    @classmethod
    def setUpClass(cls):
        cls.build = cls._build().returncode == 0
    
    def template_test(self, fname):
        with open(f'tests/{fname}.ans', 'r') as f:
            ans = f.readline()
        output = subprocess.check_output(['./cpusim', f'tests/{fname}.txt'])
        self.assertEqual(ans.strip(), output.strip(), msg=f'Failed {fname}')

    def test_compile(self):
        self.assertTrue(self.build, msg=f"failed to compile")

"""
    def test_r_type(self):
        self.template_test('23r-type')
        
    def test_all(self):
        self.template_test('23all')

    def test_addi(self):
        self.template_test('addi')
"""