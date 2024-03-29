import os

from dotenv import load_dotenv

load_dotenv()

BOT_TOKEN = str(os.getenv("BOT_TOKEN"))

admins_id = [
    261403579
]


ip = os.getenv('ip')
PostgresUser = str(os.getenv('PostgresUser'))
PostgresPassword = str(os.getenv('PostgresPassword'))
DATABASE = str(os.getenv('DATABASE'))

POSTGRES_URI = f'postgresql://{PostgresUser}:{PostgresPassword}@{ip}/{DATABASE}'