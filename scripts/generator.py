import sys
import re


class Converter(object):
    @staticmethod
    def camel_to_snake(name: str) -> str:
        """
        Converts Camel case to snake case
        :rtype: str
        """
        s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', name)
        return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower()

    @staticmethod
    def to_lower(name: str) -> str:
        return name.lower()


class ValidityChecker(object):
    @staticmethod
    def params_set(d: dict, parameters: list)-> bool:
        """
        Checks if all parameters are set
        :rtype: bool
        """
        ignore = ['guard', 'header_name']
        for param in parameters:
            if param not in d.keys() and param not in ignore:
                print("! Key {} not set. Exiting".format(param))
                return False

        return True

    @staticmethod
    def camel(s: str)-> bool:
        """
        Checks string for camel case
        :rtype: bool
        """
        return s != s.lower() and s != s.upper() and "_" not in s

    @staticmethod
    def contains_message(s: str)-> bool:
        """
        Checks if string contains keyword "Message"
        :rtype: bool
        """
        return 'Message' in s


class Generator(object):
    def __init__(self, params: list):
        self.header_template_str = ''
        self.impl_template_str = ''
        self.parameters = params

    def __del__(self):
        print("Done")

    def __check_params(self, param_dict: dict):
        """
        Checks the dictionary for validity
        :rtype: bool
        """

        param_dict['guard'] = Converter.camel_to_snake(param_dict.get('class_name')).upper()
        param_dict['header_name'] = Converter.camel_to_snake(param_dict.get('class_name'))

        if not ValidityChecker.params_set(param_dict, self.parameters):
            sys.exit()

        if not ValidityChecker.camel(param_dict.get('class_name')):
            print('Not a valid class name: needs to be camel case')
            sys.exit()

        if not ValidityChecker.contains_message(param_dict.get('class_name')):
            print("! Warning {} should include 'Message' in it's name. E.g PointMessage".format(param_dict.get('class_name')))

    def read(self, header_file: str, impl_file: str):
        print("- Using {} as template header".format(header_file))
        print("- Using {} as template impl".format(impl_file))
        self.__read_header(header_file)
        self.__read_impl(impl_file)

    def __read_header(self, header_file: str):
        with open(header_file, 'r') as f:
            self.header_template_str = f.read()
            f.close()

    def __read_impl(self, header_file: str):
        with open(header_file, 'r') as f:
            self.impl_template_str = f.read()

    def write(self, param_dict: dict):
        self.__check_params(param_dict)
        self.__write_header(param_dict)
        self.__write_impl(param_dict)

    def __write_header(self, param_dict: dict):
        generated_header_filename = Converter.camel_to_snake(param_dict.get('class_name')) + '.h'
        print("- Creating header: {}".format(generated_header_filename))
        with open(generated_header_filename, 'w') as f:
            f.write(self.header_template_str.format(**param_dict))
            f.close()

    def __write_impl(self, param_dict: dict):
        print(param_dict)
        generated_impl_filename = Converter.camel_to_snake(param_dict.get('class_name')) + '.cpp'
        print("- Creating implementation: {}".format(generated_impl_filename))
        with open(generated_impl_filename, 'w') as f:
            f.write(self.impl_template_str.format(**param_dict))
            f.close()