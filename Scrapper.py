from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time
import requests
import re
import os

class Scrapper : 
    def __init__(self):
        self.urls = {"https://www.acmicpc.net/status?user_id=gdj0208&result_id=4"}
        self.driver = webdriver.Chrome()

    def scrap_all_problems(self):
        def log_in() :
            id_box = self.driver.find_element(By.NAME, 'login_user_id')
            pw_box = self.driver.find_element(By.NAME, 'login_password')
            submit_button = self.driver.find_element(By.ID, 'submit_button')

            id_box.send_keys('gdj0208')
            pw_box.send_keys('Gdj@@010208')
            submit_button.click()
            time.sleep(3)

        def go_to_right_ans():
            self.driver.get("https://www.acmicpc.net/status?user_id=gdj0208&result_id=4")
            time.sleep(3)   

        def print_all_solution_id():
            rows = self.driver.find_elements(By.XPATH, '//table/tbody/tr')
            for row in rows:
                # 각 tr 요소에서 첫 번째 td 요소를 찾습니다.
                link = row.find_element(By.XPATH, './td[7]/a')
                quiz_num = row.find_element(By.XPATH, './td[3]')
                link.click()


                time.sleep(2)   
                code_block = self.driver.find_element(By.CSS_SELECTOR, 'div.CodeMirror-code')
                code_text = code_block.text
                lines = code_text.split('\n')
                cleaned_lines = [line.lstrip('0123456789 ') for line in lines] # 숫자와 공백 제거
                readable_code = "\n".join(cleaned_lines)

                print(readable_code)
                


        self.driver.get("https://www.acmicpc.net/login?next=%2F")
        log_in()
        go_to_right_ans()
        print_all_solution_id()

        #response = requests.get(self.urls)
        #soup = BeautifulSoup(response.content, "html.parser")
        #print(soup)

myScrapper = Scrapper()
myScrapper.scrap_all_problems()