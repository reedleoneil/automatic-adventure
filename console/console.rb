require 'rubyserial'
require 'json'
require 'securerandom'
require 'paho-mqtt'

client = PahoMqtt::Client.new()
client.connect('localhost', 1883, client.keep_alive, true, true)
client.subscribe(['lailanie', 2])

serialport = Serial.new '/dev/ttyUSB0'

Thread.new {
	while true do
		x = ''
		payload = "{"
		while x != '{' do
			x = serialport.read 1
		end
		while x != '}' do
			x = serialport.read 1
			if x != '' then payload << x end
		end
		puts payload
		begin
			payload = JSON.parse(payload)
			if payload['isTrafficLightRed'] == 0 && payload['sensorReading'] == 0 && payload['rfid'] != "" then
				uuid = SecureRandom.uuid
				`fswebcam -d /dev/video0 ~/public/#{uuid}.jpg`
				payload['image'] = "http://192.168.1.100:4567/#{uuid}.jpg"
				payload = payload.to_json
			else
				payload['image'] = ""
				payload = payload.to_json
			end
			client.publish("lailanie", payload, false, 1)
			client.loop_write
		rescue

		end
	end
}

loop do
  
end
