


class Install:
    name: str = "Instrall"

    @staticmethod
    def arguments(subparsers):
        install = subparsers.add_parser(Install.name, help='Install Gamekit in a unreal project')
        install.add_argument("name", type=str, help='Plugin name')


    @staticmethod
    def execute(args):
        pass


COMMAND = Install