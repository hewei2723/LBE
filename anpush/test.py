import requests
title=12313
content=52
url = "http://api.anpush.com/push/Q6S0WF3NXRFYUBFTEM4JRZQZ7KQ877"
payload='title&content&channel=98317'
headers = {
  'Content-Type': 'application/x-www-form-urlencoded'
}
response = requests.request("POST", url, headers=headers, data=payload)
print(response.text)