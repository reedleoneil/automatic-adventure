require 'rubyserial'
require 'paho-mqtt'

client = PahoMqtt::Client.new()
serialport = Serial.new '/dev/ttyUSB1'

client.on_message do |p|
	#puts "Topic: #{p.topic}\nPayload: #{p.payload}\nQoS: #{p.qos}"
	#serialport.write(p.payload + "\n")
#=begin
	number = p.payload[0..10]
	message = p.payload[11..p.payload.length]

	serialport.write("AT+CMGF=1\r\n")
	serialport.write("AT+CMGS=\"" + number + "\"\r\n")
	sleep 2
	serialport.write(message + "\r\cZ\r\n")
	#puts number
	#puts message
#=end
end

client.connect('localhost', 1883, client.keep_alive, true, true)
client.subscribe(["lailanie/gsm", 2])

Thread.new {
	loop do
		c = serialport.read 1
		if c != '' then printf c end
	end
}

loop do
	client.loop_read
	client.loop_write
end


