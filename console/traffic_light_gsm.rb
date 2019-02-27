require 'rubyserial'
require 'json'
require 'paho-mqtt'

client = PahoMqtt::Client.new()
serialport = Serial.new 'COM15'

client.on_message do |p|

	puts "Topic: #{p.topic}\nPayload: #{p.payload}\nQoS: #{p.qos}"
	serialport.write p.payload
end

client.connect('192.168.1.100', 1883, client.keep_alive, true, true)
client.subscribe(["lailanie/gsm", 2])

Thread.new {
loop do
  serialport.write "t1_green"
  sleep 5
  serialport.write "t1_yellow"
  sleep 2
  serialport.write "t2_green"
  sleep 5
  serialport.write "t2_yellow"
  sleep 2
  serialport.write "t3_green"
  sleep 5
  serialport.write "t3_yellow"
  sleep 2
end
}

loop do
  client.loop_write
  client.loop_read
end
